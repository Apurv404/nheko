/*
 * nheko Copyright (C) 2017  Konstantinos Sideris <siderisk@auth.gr>
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

#pragma once

#include <QSplitter>

namespace splitter {
struct SideBarSizes
{
        int small;
        int normal;
        int groups;
        int collapsePoint;
};

SideBarSizes
calculateSidebarSizes(const QFont &f);
}

class Splitter : public QSplitter
{
        Q_OBJECT
public:
        explicit Splitter(QWidget *parent = nullptr);
        ~Splitter();

        void restoreSizes(int fallback);

public slots:
        void hideSidebar();
        void showFullRoomList();
        void showChatView();

signals:
        void hiddenSidebar();

private:
        void onSplitterMoved(int pos, int index);

        int moveEventLimit_ = 50;

        int leftMoveCount_  = 0;
        int rightMoveCount_ = 0;

        splitter::SideBarSizes sz_;
};
