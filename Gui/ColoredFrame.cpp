/* ***** BEGIN LICENSE BLOCK *****
 * This file is part of Natron <https://natrongithub.github.io/>,
 * (C) 2018-2022 The Natron developers
 * (C) 2013-2018 INRIA and Alexandre Gauthier-Foichat
 *
 * Natron is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Natron is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Natron.  If not, see <http://www.gnu.org/licenses/gpl-2.0.html>
 * ***** END LICENSE BLOCK ***** */

// ***** BEGIN PYTHON BLOCK *****
// from <https://docs.python.org/3/c-api/intro.html#include-files>:
// "Since Python may define some pre-processor definitions which affect the standard headers on some systems, you must include Python.h before any standard headers are included."
#include <Python.h>
// ***** END PYTHON BLOCK *****

#include "ColoredFrame.h"

NATRON_NAMESPACE_ENTER

ColoredFrame::ColoredFrame(QWidget* parent)
    : QFrame(parent)
    , _frameColor(Qt::black)
{
}

ColoredFrame::~ColoredFrame()
{
}

const QColor&
ColoredFrame::getFrameColor()
{
    return _frameColor;
}

void
ColoredFrame::setFrameColor(const QColor& color)
{
    _frameColor = color;

    setStyleSheet( QString::fromUtf8("ColoredFrame { border:1px solid rgb(%1, %2, %3); border-radius: 2px; }").arg( color.red() ).arg( color.green() ).arg( color.blue() ) );
}

NATRON_NAMESPACE_EXIT
NATRON_NAMESPACE_USING
#include "moc_ColoredFrame.cpp"
