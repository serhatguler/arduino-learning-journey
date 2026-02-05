enum RobotState {
  SEARCH,
  MOVE,
  AVOID
};

RobotState robotState = SEARCH;

void loop() {
  switch (robotState) {
    case SEARCH:
      // rotate robot
      if (true) robotState = MOVE;
      break;

    case MOVE:
      // move forward
      if (false) robotState = AVOID;
      break;

    case AVOID:
      // obstacle avoidance
      robotState = SEARCH;
      break;
  }
}


