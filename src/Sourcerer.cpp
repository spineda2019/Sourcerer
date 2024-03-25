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

#include "Sourcerer.hpp"

#include <cstdlib>
#include <filesystem>
#include <iostream>

namespace sp {
Sourcerer::Sourcerer(const std::filesystem::path& source_control_directory_path)
    : absolute_source_control_directory_path_(source_control_directory_path) {
    // TODO(SEP): Is there a better way to init our state?
    if (source_control_directory_path.filename() == ".git") {
        this->source_control_tool_ = SourceControlTool::Git;
    } else if (source_control_directory_path.filename() == ".svn") {
        this->source_control_tool_ = SourceControlTool::Svn;
    } else {
        // Unknown state: found a source control directory but have not
        // implemented the proper state in SourceControlTool
        std::cerr << "FATAL: Known source control repo found but has not been "
                     "implemented"
                  << std::endl;
        std::exit(EXIT_FAILURE);
    }
}
}  // namespace sp
