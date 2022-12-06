using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor RightF;
extern motor RightB;
extern motor LeftF;
extern motor LeftB;
extern motor FlyWheel;
extern motor Intake;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );