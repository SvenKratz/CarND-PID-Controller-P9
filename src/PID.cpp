#include "PID.h"
#include <iostream>


using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID()  : p_error(0), i_error(0), d_error(0), last_cte(0), steer(0) {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_)  {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
}

void PID::UpdateError(double cte) {
   d_error = cte-last_cte;
   i_error += cte;
   steer =  -Kp * cte - Kd * d_error - Ki * i_error;
   cout << "steer " << steer << "d_error " << d_error << " i_error " << i_error <<  endl;
   last_cte = cte;
}

double PID::GetSteer()
{
  // clamp to steering command
  if (steer > 0)
  {
    return min(steer, 1.0);
  }
  else
  {
    return max(steer, -1.0);
  }
}

double PID::TotalError() {
}
