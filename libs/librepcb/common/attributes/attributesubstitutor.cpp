/*
 * LibrePCB - Professional EDA for everyone!
 * Copyright (C) 2013 LibrePCB Developers, see AUTHORS.md for contributors.
 * http://librepcb.org/
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*****************************************************************************************
 *  Includes
 ****************************************************************************************/
#include <QtCore>
#include "attributesubstitutor.h"
#include "attributeprovider.h"

/*****************************************************************************************
 *  Namespace
 ****************************************************************************************/
namespace librepcb {

/*****************************************************************************************
 *  Public Methods
 ****************************************************************************************/

QString AttributeSubstitutor::substitute(QString str, const AttributeProvider* ap) noexcept
{
    int startPos = 0;
    int length = 0;
    QString value;
    QStringList keys;
    QSet<QString> keyBacktrace; // avoid endless recursion
    while (searchVariablesInText(str, startPos, startPos, length, keys)) {
        if (keys.count() > 0) {
            bool keyFound = false;
            foreach (const QString& key, keys) {
                if (key == "$") {
                    // replace "$$" by "$" (escaping)
                    str.remove(startPos, 1);
                    startPos++;
                    keyFound = true;
                    break;
                } else if ((getValueOfKey(key, value, ap)) && (!keyBacktrace.contains(key))) {
                    // replace "$KEY" with the value of KEY
                    str.replace(startPos, length, value);
                    keyBacktrace.insert(key);
                    keyFound = true;
                    break;
                }
            }
            if (!keyFound) {
                // attribute not found, remove "$KEY" from str
                str.remove(startPos, length);
            }
        } else {
            // standalone "$", skip it
            startPos++;
        }
    }
    return str;
}

/*****************************************************************************************
 *  Private Methods
 ****************************************************************************************/

bool AttributeSubstitutor::searchVariablesInText(const QString& text, int startPos, int& pos,
                                                 int& length, QStringList& keys) noexcept
{
    QString singleKey = "[A-Za-z][_0-9A-Za-z]*";
    QString multiKey = "\\{(" % singleKey % ")(\\:" % singleKey % ")*\\}";
    QString pattern = "\\$(\\$|((" % singleKey % ")|(" % multiKey % ")))";
    QRegularExpression re(pattern);
    QRegularExpressionMatch match = re.match(text, startPos);
    if (match.hasMatch() && match.capturedLength() > 1) {
        pos = match.capturedStart();
        length = match.capturedLength();
        QString rawKeys = match.captured(1).remove('{').remove('}');
        keys = rawKeys.split(':');
        return true;
    } else {
        return false;
    }
}

bool AttributeSubstitutor::getValueOfKey(const QString& key, QString& value,
                                         const AttributeProvider* ap) noexcept
{
    if (ap) {
        value = ap->getAttributeValue(key);
        return !value.isEmpty();
    } else {
        return false;
    }
}

/*****************************************************************************************
 *  End of File
 ****************************************************************************************/

} // namespace librepcb
