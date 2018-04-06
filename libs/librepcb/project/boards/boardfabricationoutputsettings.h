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

#ifndef LIBREPCB_PROJECT_BOARDFABRICATIONOUTPUTSETTINGS_H
#define LIBREPCB_PROJECT_BOARDFABRICATIONOUTPUTSETTINGS_H

/*****************************************************************************************
 *  Includes
 ****************************************************************************************/
#include <QtCore>
#include <librepcb/common/fileio/serializableobject.h>

/*****************************************************************************************
 *  Namespace / Forward Declarations
 ****************************************************************************************/
namespace librepcb {
namespace project {

class Board;

/*****************************************************************************************
 *  Class BoardFabricationOutputSettings
 ****************************************************************************************/

/**
 * @brief The BoardFabricationOutputSettings class
 */
class BoardFabricationOutputSettings final : public SerializableObject
{
    public:

        // Constructors / Destructor
        BoardFabricationOutputSettings() = delete;
        BoardFabricationOutputSettings(const BoardFabricationOutputSettings& other) = delete;
        BoardFabricationOutputSettings(const Board& board) noexcept;
        BoardFabricationOutputSettings(const Board& board,
                                       const BoardFabricationOutputSettings& other) noexcept;
        BoardFabricationOutputSettings(const Board& board, const SExpression& node) noexcept;
        ~BoardFabricationOutputSettings() noexcept;

        // Getters
        const QString& getOutputBasePath()          const noexcept {return mOutputBasePath;}
        const QString& getFileNameDrills()          const noexcept {return mFileNameDrills;}
        const QString& getFileNameOutlines()        const noexcept {return mFileNameOutlines;}
        const QString& getFileNameCopperTop()       const noexcept {return mFileNameCopperTop;}
        const QString& getFileNameCopperInner()     const noexcept {return mFileNameCopperInner;}
        const QString& getFileNameCopperBot()       const noexcept {return mFileNameCopperBot;}
        const QString& getFileNameSoldermaskTop()   const noexcept {return mFileNameSoldermaskTop;}
        const QString& getFileNameSoldermaskBot()   const noexcept {return mFileNameSoldermaskBot;}
        const QString& getFileNameSilkscreenTop()   const noexcept {return mFileNameSilkscreenTop;}
        const QString& getFileNameSilkscreenBot()   const noexcept {return mFileNameSilkscreenBot;}

        /// @copydoc librepcb::SerializableObject::serialize()
        void serialize(SExpression& root) const override;

        // Operator Overloadings
        BoardFabricationOutputSettings& operator=(const BoardFabricationOutputSettings& rhs) noexcept;


    private: // Data
        const Board& mBoard;
        QString mOutputBasePath;
        QString mFileNameDrills;
        QString mFileNameOutlines;
        QString mFileNameCopperTop;
        QString mFileNameCopperInner;
        QString mFileNameCopperBot;
        QString mFileNameSoldermaskTop;
        QString mFileNameSoldermaskBot;
        QString mFileNameSilkscreenTop;
        QString mFileNameSilkscreenBot;
};

/*****************************************************************************************
 *  End of File
 ****************************************************************************************/

} // namespace project
} // namespace librepcb

#endif // LIBREPCB_PROJECT_BOARDFABRICATIONOUTPUTSETTINGS_H
