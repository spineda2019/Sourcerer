/*
   Copyright 2024 Sebastian Pineda (spineda.wpi.alum@gmail.com)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */

#include <filesystem>
#include <optional>
#include <string_view>

namespace sp {
bool IsDirectoryASourceControlDirectory(const std::string_view directory) {
    return false;
}

std::optional<std::filesystem::path> FindSourceControlDirectory() {
    std::filesystem::path cwd(std::filesystem::current_path());

    for (const auto& entry : std::filesystem::directory_iterator(cwd)) {
        if (entry.is_directory() && IsDirectoryASourceControlDirectory(
                                        entry.path().filename().c_str())) {
            return entry;
        }
    }

    return {};
}
}  // namespace sp