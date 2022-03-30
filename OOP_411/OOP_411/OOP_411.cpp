#include <iostream>
#include "Base_class.h"
#include "app.h"
int main()
{
    Application* app = new Application();
    app->build_tree();
    return app->exec();

}