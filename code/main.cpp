/***********************

Parallelizing Reinforcement Learning 

Author: Naresh Balaji Ravichandran

************************/

#include "main.h"
#include "grid.cpp"

class rl
{
 private:
  int **action;
  int **policy;
  
 public:
  rl(int M=M_default, int N=N_default)
  {
    int action[NUM_ACTION][2] =
    {
      {-1, 0},
      { 1, 0},
      { 0, 1},
      { 0,-1}
    };
    
    policy = (int**)malloc(M*N*sizeof(int*));
    for(int i=0; i<NUM_ACTION; i++)
    {
      policy
    }
    
  }
};  

int main(int argc, char *argv[])
{
  std::cout<<"\nHello World!";

  grid grid1;
  grid1.throw_bot_at(2,1);
  grid1.throw_food_at();

  for(int i=0; i<100; i++)
  {    
    grid1.move_bot_by(1,1);
    grid1.advance_timestep();
    grid1.print_state();
  }

  return 0;
}
