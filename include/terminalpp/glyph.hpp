#ifndef TERMINALPP_ANSI_GLYPH_HPP_
#define TERMINALPP_ANSI_GLYPH_HPP_

#include <iosfwd>
#include "terminalpp/ansi/protocol.hpp"

namespace terminalpp {

//* =========================================================================
/// \brief A structure that carries around the character attributes of an
/// ANSI element.
//* =========================================================================
struct glyph
{
    //* =====================================================================
    /// \brief Default Constructor
    /// \par
    /// Note: the default glyph is chosen as a space character US ASCII
    /// character set.  That is, it is blank.
    //* =====================================================================
    constexpr glyph(
        char character = ' ',
        terminalpp::ansi::charset charset =
            terminalpp::ansi::charset::us_ascii)
      : character_(character),
        charset_(charset)
    {
    }

    char                      character_;
    terminalpp::ansi::charset charset_;
};

// ==========================================================================
// OPERATOR==
// ==========================================================================
constexpr bool operator==(glyph const &lhs, glyph const &rhs)
{
    return lhs.character_ == rhs.character_
        && lhs.charset_   == rhs.charset_;
}

// ==========================================================================
// OPERATOR!=
// ==========================================================================
constexpr bool operator!=(glyph const &lhs, glyph const &rhs)
{
    return !(lhs == rhs);
}

std::ostream &operator<<(std::ostream &out, glyph const &attr);

//* =========================================================================
/// \brief Returns whether a particular glyph is printable.
//* =========================================================================
bool is_printable(glyph const &gly);

}

#endif
