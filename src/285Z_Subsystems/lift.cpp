/*
class lift{
public

  double liftAngle;
  bool liftState;
  void liftPosition(int position){
    liftMotor.moveAbsolute(position);

void liftUp(){
  if(liftUpButton.isPressed()){
    liftMotor.moveVelocity(-100);
  }
  if (!liftUpButton.isPressed()&&!liftDownButton.isPressed()){
    liftMotor.moveVelocity(0);
    liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
}
void liftDown(){
  if(liftDownButton.isPressed()){
    liftMotor.moveVelocity(100);
  }
  if (!liftUpButton.isPressed()&&!liftDownButton.isPressed()){
    liftMotor.moveVelocity(0);
    liftMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  }
}

void manualLiftControl(){
  liftUp();
  liftDown();
}
*/
