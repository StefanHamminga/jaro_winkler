/**@file
 * @brief Jaro-Winkler string similarity implementation
 * @author Stefan Hamminga <s@stefanhamminga.com>
 */

#pragma once

#include <cstddef>
#include <cstdint>
#include <algorithm>
#include <string_view>

namespace edit_distance {
    template <typename T = float>
    constexpr T jaro_winkler(const std::string_view source,
                                 const std::string_view target,
                                 const unsigned length,
                                 const T bias)
    {
        const unsigned sl = source.length();
        const unsigned tl = target.length();
        if (sl == 0) {
            return tl == 0 ? 1.0 : 0.0;
        }
        const auto match_distance = std::max(sl, tl) / 2 - 1;
        // bool source_matches[sl];
        // bool target_matches[tl];
        // std::fill(source_matches, source_matches + sl, false);
        // std::fill(target_matches, target_matches + tl, false);
        auto source_matches = new bool[sl] {0};
        auto target_matches = new bool[tl] {0};
        unsigned matches = 0;
        for (unsigned i = 0; i < sl; ++i) {
                const auto end = std::min(i + match_distance + 1, tl);
                for (auto k = i > match_distance ? (i - match_distance) : 0u; k < end; ++k) {
                if (!target_matches[k] && source[i] == target[k]) {
                    source_matches[i] = true;
                    target_matches[k] = true;
                    ++matches;
                    break;
                }
            }
        }
        if (matches == 0) {
            delete[] source_matches;
            delete[] target_matches;
            return 0.0;
        }
        T t = 0.0;
        unsigned k = 0;
        for (unsigned i = 0; i < sl; ++i) {
            if (source_matches[i]) {
                while (!target_matches[k]) ++k;
                if (source[i] != target[k]) t += 0.5;
                ++k;
            }
        }

        const T m = matches;
        delete[] source_matches;
        delete[] target_matches;
        return (m / sl + m / tl + (m - t) / m) / 3.0;
    }
} // namespace edit_distance
