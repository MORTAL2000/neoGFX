// alignment.hpp
/*
  neogfx C++ GUI Library
  Copyright (c) 2019 Leigh Johnston.  All Rights Reserved.
  
  This program is free software: you can redistribute it and / or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <neogfx/neogfx.hpp>
#include <neolib/i_enum.hpp>

namespace neogfx
{
    enum class alignment : uint32_t
    {
        None = 0x0000,
        Left = 0x0001,
        Right = 0x0002,
        Centre = 0x0004,
        Center = alignment::Centre,
        Justify = 0x0008,
        Top = 0x0010,
        VCentre = 0x0020,
        VCenter = alignment::VCentre,
        Bottom = 0x0040,
        Horizontal = Left | Centre | Right | Justify,
        Vertical = Top | VCentre | Bottom
    };
}

template <>
const neolib::enum_enumerators_t<neogfx::alignment> neolib::enum_enumerators_v<neogfx::alignment>
{
    declare_enum_string(neogfx::alignment, None)
    declare_enum_string(neogfx::alignment, Left)
    declare_enum_string(neogfx::alignment, Right)
    declare_enum_string(neogfx::alignment, Centre)
    declare_enum_string(neogfx::alignment, Center)
    declare_enum_string(neogfx::alignment, Justify)
    declare_enum_string(neogfx::alignment, Top)
    declare_enum_string(neogfx::alignment, VCentre)
    declare_enum_string(neogfx::alignment, VCenter)
    declare_enum_string(neogfx::alignment, Bottom)
    declare_enum_string(neogfx::alignment, Horizontal) 
    declare_enum_string(neogfx::alignment, Vertical)
};

namespace neogfx
{
    inline constexpr alignment operator|(alignment aLhs, alignment aRhs)
    {
        return static_cast<alignment>(static_cast<uint32_t>(aLhs) | static_cast<uint32_t>(aRhs));
    }

    inline constexpr alignment operator&(alignment aLhs, alignment aRhs)
    {
        return static_cast<alignment>(static_cast<uint32_t>(aLhs) & static_cast<uint32_t>(aRhs));
    }

}
