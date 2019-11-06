class lift{
public:

  double liftAngle;
  bool liftState;

  void liftPosition(position){
    liftMotor.moveAbsolute(position);
  }

};
