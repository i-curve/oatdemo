#pragma once

#include <oatpp/orm/SchemaMigration.hpp>
#include <oatpp/orm/DbClient.hpp>
#include <oatpp/core/macro/codegen.hpp>

#include OATPP_CODEGEN_BEGIN(DbClient)

class MyClient : public oatpp::orm::DbClient {
public:
    MyClient(const std::shared_ptr<oatpp::orm::Executor> &executor)
        : oatpp::orm::DbClient(executor) {}

    // QUERY(createUser,
    //       "insert into users(username,email,role) "
    //       "values(:username,:email,:role);",
    //       PARAM(oatpp::String, username), PARAM(oatpp::String, email),
    //       PARAM(oatpp::Enum<UserRoles>::AsString, role))

    //
    QUERY(getUserByName, "select * from users where username=:username;",
          PARAM(oatpp::String, username))
};
#include OATPP_CODEGEN_END(DbClient)