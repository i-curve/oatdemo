/* c++
 * @Author: curve
 * @Date: 2022-11-24 14:08:27
 * @Last Modified by: curve
 * @Last Modified time: 2022-11-24 23:49:33
 */
#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <oatpp/web/server/HttpConnectionHandler.hpp>
#include <oatpp/network/tcp/server/ConnectionProvider.hpp>
#include <oatpp/core/macro/component.hpp>

// #include "dao/client.hpp"
// #include <oatpp-sqlite/orm.hpp>

class AppComponent {
public:
    /**
     * @brief
     *
     */
    OATPP_CREATE_COMPONENT(
        std::shared_ptr<oatpp::network::ServerConnectionProvider>,
        serverConnectionProvider)
    ([]() {
        return oatpp::network::tcp::server::ConnectionProvider::createShared(
            {"localhost", 8000, oatpp::network::Address::IP_4});
    }());

    /**
     * @brief
     *
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>,
                           httpRouter)
    ([]() { return oatpp::web::server::HttpRouter::createShared(); }());

    /**
     * @brief
     *
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>,
                           connectonHandler)
    ([]() {
        OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>,
                        router); // get Router component
        return oatpp::web::server::HttpConnectionHandler::createShared(router);
    }());

    /**
     * @brief
     *
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>,
                           apiObjectMapper)
    ([]() {
        return oatpp::parser::json::mapping::ObjectMapper::createShared();
    }());

    // /**
    //  * @brief DbClient component
    //  *
    //  */
    // OATPP_CREATE_COMPONENT(std::shared_ptr<MyClient>, myDatabaseClient)
    // ([] {
    //     auto connectionProvider =
    //         std::make_shared<oatpp::sqlite::ConnectionProvider>(
    //             "./database.sqlite");
    //     auto executor =
    //         std::make_shared<oatpp::sqlite::Executor>(connectionProvider);
    //     return std::make_shared<MyClient>(executor);
    // }());
};