/* c++
 * @Author: curve
 * @Date: 2022-11-24 14:09:27
 * @Last Modified by: curve
 * @Last Modified time: 2022-11-24 23:50:08
 */
#pragma once

#include "../dto/DTO.hpp"
#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/macro/component.hpp>

#include OATPP_CODEGEN_BEGIN(ApiController)

class MyController : public oatpp::web::server::api::ApiController {
public:
    /**
     * @brief
     *
     */
    MyController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
        : oatpp::web::server::api::ApiController(objectMapper) {}

public:
    ENDPOINT("GET", "/hello", root) {
        // OATPP_COMPONENT(std::shared_ptr<MyClient>, client);

        auto dto = MessageDTO::createShared();
        dto->statusCode = 200;
        dto->message = "Hello world!";
        return createDtoResponse(Status::CODE_200, dto);
    }
};

#include OATPP_CODEGEN_END(ApiController)