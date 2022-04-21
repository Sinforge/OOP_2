#include <iostream>
#include "Base_class.h"
#include "app.h"
int main()
{
    setlocale(LC_ALL, "");
    Application* app = new Application();
    app->built_tree_objs();
    app->set_tree_condition();
    return app->exec();

}