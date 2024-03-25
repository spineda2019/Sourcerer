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

#include <iostream>
#include <optional>

#include "include/Sourcerer.hpp"
#include "include/directory_explorer.hpp"

int main(void) {
    std::optional<std::filesystem::path> dir(sp::FindSourceControlDirectory());

    if (!dir.has_value()) {
        std::cerr << "Not in a Source Controlled Directery!" << std::endl;
        return -1;
    }

    sp::Sourcerer sourcerer(dir.value());

    return 0;
}
