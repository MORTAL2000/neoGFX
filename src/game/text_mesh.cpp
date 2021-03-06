// text_mesh.cpp
/*
  neogfx C++ GUI Library
  Copyright (c) 2015 Leigh Johnston.  All Rights Reserved.
  
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

#include <neogfx/neogfx.hpp>
#include <neogfx/game/rectangle.hpp>
#include <neogfx/game/text_mesh.hpp>

namespace neogfx::game
{
    namespace shape
    {
        text::text(i_ecs& aEcs, const i_graphics_context& aGraphicsContext, const std::string& aText, const neogfx::font& aFont, const neogfx::text_appearance& aAppearance, neogfx::alignment aAlignment) :
            entity{ aEcs, archetype().id() }
        {
            auto& font = aEcs.shared_component<game::font>().populate(to_string(neolib::generate_uuid()), game::font{ { service<i_font_manager>(), aFont.id() }, aFont.family_name(), aFont.style_name(), aFont.size(), aFont.underline() });
            auto& textMesh = aEcs.component<game::text_mesh>().populate(id(), game::text_mesh
                {
                    aText,
                    {},
                    {},
                    {},
                    aAlignment,
                    { &font },
                    { to_ecs_component(aAppearance.ink()) },
                    aAppearance.effect() ? aAppearance.effect()->type() : text_effect_type::None,
                    { aAppearance.effect() ? to_ecs_component(aAppearance.effect()->colour()) : game::material{} },
                    aAppearance.effect() ? aAppearance.effect()->width() : 0.0
                });
            game::text_mesh::meta::update(textMesh, aEcs, aGraphicsContext, id());
        }

        text::text(const text& aOther) :
            entity{ aOther.ecs(), archetype().id() }
        {
            // todo: clone entity
        }
    }
}