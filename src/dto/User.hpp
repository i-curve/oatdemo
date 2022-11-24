#pragma once

#include <oatpp/core/Types.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/macro/component.hpp>

#include OATPP_CODEGEN_BEGIN(DTO)

class UserDTO : public oatpp::DTO {
    DTO_INIT(UserDTO, DTO)

    DTO_FIELD(Int32, id);
    DTO_FIELD(String, username);
    DTO_FIELD(Int32, age);
    // DTO_FIELD(String, password);
};
#include OATPP_CODEGEN_END(DTO)