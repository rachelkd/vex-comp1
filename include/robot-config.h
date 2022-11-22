using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor RightUp;
extern motor RightDown;
extern motor LeftForward;
extern motor LeftDown;
extern motor FlyWheel;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );