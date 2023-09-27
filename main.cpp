#include "graphics.h"
#include "Interface.h"
#include "config.h"
#include "movie.h"
#include <iostream>

// where inputs and updates are placed
void update(float ms) 
{
    Interface* inte = Interface::getInstance();
    inte->update();
   
    };


// The window content drawing function.
void draw()
{
    Interface* inte = Interface::getInstance();
    inte->draw();

}
int main()
{
    // initialization of our movie obj
    
   
    
    Interface* interface = Interface::getInstance(); /*with this declaration we call the interface constructor*/
    interface->init();//initialization of our movie obj;

    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Moviebrowse");

    graphics::setUserData(interface);


    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(1000, 500);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT); /* maximum dimension canvas */

    graphics::startMessageLoop();

    Interface::releaseInstance();// we delete the pointer ;

    return 0;
}