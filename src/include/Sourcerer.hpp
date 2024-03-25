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

#ifndef SRC_INCLUDE_SOURCERER_HPP_
#define SRC_INCLUDE_SOURCERER_HPP_

#include <cstdint>
#include <filesystem>

namespace sp {
enum class SourceControlTool : std::uint8_t {
    Git,
    Svn,
};

class Sourcerer {
 public:
    explicit Sourcerer(
        const std::filesystem::path& source_control_directory_path);

    void ExtractDetails() const;

 private:
    void ParseGitFolder() const;
    void ParseSvnFolder() const;

    const std::filesystem::path absolute_source_control_directory_path_;
    SourceControlTool source_control_tool_;
};
}  // namespace sp

#endif  // SRC_INCLUDE_SOURCERER_HPP_
