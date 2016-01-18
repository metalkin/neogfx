// i_native_graphics_context.hpp
/*
  neogfx C++ GUI Library
  Copyright(C) 2016 Leigh Johnston
  
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

#include "neogfx.hpp"
#include "geometry.hpp"
#include "path.hpp"
#include "graphics_context.hpp"

namespace neogfx
{
	class i_native_graphics_context
	{
	public:
		virtual ~i_native_graphics_context() {}
		virtual std::unique_ptr<i_native_graphics_context> clone() const = 0;
	public:
		virtual void flush() = 0;
		virtual void scissor_on(const rect& aRect) = 0;
		virtual void scissor_off() = 0;
		virtual optional_rect scissor_rect() const = 0;
		virtual void clip_to(const rect& aRect) = 0;
		virtual void clip_to(const path& aPath, dimension aPathOutline = 0) = 0;
		virtual void reset_clip() = 0;
		virtual smoothing_mode_e smoothing_mode() const = 0;
		virtual smoothing_mode_e set_smoothing_mode(smoothing_mode_e aSmoothingMode) = 0;
		virtual void clear(const colour& aColour) = 0;
		virtual void set_pixel(const point& aPoint, const colour& aColour) = 0;
		virtual void draw_pixel(const point& aPoint, const colour& aColour) = 0;
		virtual void draw_line(const point& aFrom, const point& aTo, const pen& aPen) = 0;
		virtual void draw_rect(const rect& aRect, const pen& aPen) = 0;
		virtual void draw_path(const path& aPath, const pen& aPen) = 0;
		virtual void fill_solid_rect(const rect& aRect, const colour& aColour) = 0;
		virtual void fill_gradient_rect(const rect& aRect, const gradient& aGradient) = 0;
		virtual void fill_and_draw_path(const path& aPath, const colour& aFillColour, const pen& aPen) = 0;
		virtual glyph_text to_glyph_text(text::const_iterator aTextBegin, text::const_iterator aTextEnd, const font& aFont) const = 0;
		virtual void begin_drawing_glyphs() = 0;
		virtual void draw_glyph(const point& aPoint, const glyph& aGlyph, const font& aFont, const colour& aColour) = 0;
		virtual void end_drawing_glyphs() = 0;
	};
}