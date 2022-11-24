/* c++
 * @Author: curve
 * @Date: 2022-11-24 14:06:32
 * @Last Modified by: curve
 * @Last Modified time: 2022-11-24 20:43:04
 */
#include <oatpp/network/Server.hpp>
#include "AppComponent.hpp"
#include "controller/MyController.hpp"
#include "controller/UserController.hpp"

void run() {
    // register components in scope of run() method
    AppComponent components;

    // get router
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);
    // router->route("GET", "/hello", std::make_shared<myController>());

    // 添加 MyController 控制器
    auto myController = std::make_shared<MyController>();
    router->addController(myController);

    // 添加 UserController 控制器
    auto userController = std::make_shared<UserController>();
    router->addController(userController);

    // get connection handler component
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>,
                    connectionHandler);
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>,
                    connectionProvider);
    oatpp::network::Server server(connectionProvider, connectionHandler);

    OATPP_LOGI("OATDEMO", "Server running on port %s",
               connectionProvider->getProperty("port").getData());
    // run server;
    server.run();
}

int main() {

    // init oatpp environment
    oatpp::base::Environment::init();

    run();
    // destroy oatpp environment
    oatpp::base::Environment::destroy();
    return 0;
}