#pragma once

#include "../dto/User.hpp"
#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/macro/component.hpp>
#include <oatpp/parser/json/Beautifier.hpp>
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class UserController : public oatpp::web::server::api::ApiController {
public:
    /**
     * @brief 构造函数
     *
     */
    UserController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
        : oatpp::web::server::api::ApiController(objectMapper) {}

public:
    /**
     * @brief 获取用户列表
     *
     */
    ENDPOINT("GET", "/users", listUser) {

        OATPP_LOGI("get: /users=", "%s", "---------------------");
        auto user1 = UserDTO::createShared();
        user1->id = 1;
        user1->username = "小王";
        user1->age = 12;
        // res->push_back(user1);
        OATPP_LOGI("get: /users=", "%s", "---------------------");
        auto user2 = UserDTO::createShared();
        user2->id = 2;
        user2->username = "小李";
        user2->age = 16;
        // res->push_back(user2);
        OATPP_LOGI("get: /users=", "%s", "---------------------");
        auto user3 = UserDTO::createShared();
        user3->id = 3;
        user3->username = "小张";
        user3->age = 14;
        // res->push_back(user3);

        oatpp::List<oatpp::Object<UserDTO>> res = {user1, user2, user3};
        auto res2 = oatpp::List<oatpp::Object<UserDTO>>::createShared();
        res2->push_back(user1);
        res2->push_back(user2);
        res2->push_back(user3);

        /* create serializer and deserializer configurations */
        auto serializeConfig =
            oatpp::parser::json::mapping::Serializer::Config::createShared();
        auto deserializeConfig =
            oatpp::parser::json::mapping::Deserializer::Config::createShared();

        /* enable beautifier */
        serializeConfig->useBeautifier = true;

        /* create json object mapper with serializer config */
        auto jsonObjectMapper =
            oatpp::parser::json::mapping::ObjectMapper::createShared(
                serializeConfig, deserializeConfig);
        oatpp::String str = jsonObjectMapper->writeToString(res2);
        OATPP_LOGI("message", str->c_str());
        return createDtoResponse(Status::CODE_200, res2);
    };

    /**
     * @brief 获取用户详情
     * path: id 用户id
     */
    ENDPOINT("GET", "/user/{id}", getUser, PATH(Int32, id),
             QUERIES(QueryParams, queryParams)) {
        OATPP_LOGI("PATH", "id=%d", *id.get())
        for (auto &param : queryParams.getAll()) {
            OATPP_LOGI("PARAMS", "%s=%s", param.first.getData(),
                       param.second.getData())
        }
        auto user1 = UserDTO::createShared();
        user1->id = id;
        user1->username = "小王";
        user1->age = 12;
        return createDtoResponse(Status::CODE_200, user1);
        // return createResponse(Status::CODE_404);
    }
};

#include OATPP_CODEGEN_END(ApiController)