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
#include "boardfabricationoutputsettings.h"
#include "board.h"

/*****************************************************************************************
 *  Namespace
 ****************************************************************************************/
namespace librepcb {
namespace project {

/*****************************************************************************************
 *  Constructors / Destructor
 ****************************************************************************************/

BoardFabricationOutputSettings::BoardFabricationOutputSettings(const Board& board) noexcept :
    mBoard(board), mOutputBasePath("./output/#VERSION/gerber/#PROJECT||_"),
    mFileNameDrills("DRILLS-PTH.drl"),
    mFileNameOutlines("OUTLINES.gbr"),
    mFileNameCopperTop("COPPER-TOP.gbr"),
    mFileNameCopperInner("COPPER-IN#LAYER.gbr"),
    mFileNameCopperBot("COPPER-BOTTOM.gbr"),
    mFileNameSoldermaskTop("SOLDERMASK-TOP.gbr"),
    mFileNameSoldermaskBot("SOLDERMASK-BOTTOM.gbr"),
    mFileNameSilkscreenTop("SILKSCREEN-TOP.gbr"),
    mFileNameSilkscreenBot("SILKSCREEN-BOTTOM.gbr")
{
}

BoardFabricationOutputSettings::BoardFabricationOutputSettings(const Board& board,
        const BoardFabricationOutputSettings& other) noexcept :
    BoardFabricationOutputSettings(board) // init and load defaults
{
    *this = other;
}

BoardFabricationOutputSettings::BoardFabricationOutputSettings(const Board& board,
        const SExpression& node) noexcept :
    BoardFabricationOutputSettings(board) // init and load defaults
{
    Q_UNUSED(node);
}

BoardFabricationOutputSettings::~BoardFabricationOutputSettings() noexcept
{
}

/*****************************************************************************************
 *  General Methods
 ****************************************************************************************/

void BoardFabricationOutputSettings::serialize(SExpression& root) const
{
    Q_UNUSED(root);
}

/*****************************************************************************************
 *  Operator Overloadings
 ****************************************************************************************/

BoardFabricationOutputSettings& BoardFabricationOutputSettings::operator=(
    const BoardFabricationOutputSettings& rhs) noexcept
{
    Q_UNUSED(rhs);
    return *this;
}

/*****************************************************************************************
 *  Private Methods
 ****************************************************************************************/


/*****************************************************************************************
 *  End of File
 ****************************************************************************************/

} // namespace project
} // namespace librepcb
