class lift{
public:

  double liftAngle;
  bool liftState;
  void liftPosition(int position){
    liftMotor.moveAbsolute(position);
    
  }

};

lift myLift(0){
}
myLift.liftAngle
