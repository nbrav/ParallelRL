#include "main.h"

class grid
{
 private:
  
  int **grid1, M, N;
  int bot_x, bot_y;
  int current_time;
  bool reward;
  
 public:
  
  //init grid with size MxN;
  grid(int M=M_default, int N=N_default)
  {
    std::cout<<"\nInitializing grid "<<M<<"x"<<N<<"...";
    this->M = M;
    this->N = N;
    current_time = 0;
    grid1 = (int**)malloc(M*sizeof(int*));

    for(int i=0; i<M; i++)
    {
      grid1[i] = (int*)malloc(N*sizeof(int));
    }

    for(int i=0;i<M;i++)
      for(int j=0; j<N;j++)
      {
	grid1[i][j] = 0;
      }
  }
    
  ~grid()
  {
    std::cout<<"\nClosing the grid...";
    for(int i=0; i<M; i++)
    {
      free(grid1[i]);
    }
    free(grid1);
  }
  
  //init bot at position (x,y);
  void throw_bot_at(int x, int y)
  {
    if(x>=M || y>=N)
    {
      return;
    }
    bot_x = x;
    bot_y = y;
  }

  //init food at position(*x,*y)
  void throw_food_at()
  {
    for(int i=0; i<NUM_FOOD; i++)
    {
      grid1[FOOD1_X][FOOD1_Y] = 1;
    }    
  }

  //
  bool is_food_at(int x, int y)
  {
    if(grid1[x][y] == 1)
      return true;
    else
      return false;
  }
  
  //move bot
  void move_bot_by(int x, int y)
  {
    bot_x += x;
    bot_y += y;

    bot_x %= M;
    bot_y %= N;
  }
  
  //get position()  
  void print_state()
  {
    std::cout<<"\n TIME("<<current_time<<")";
    std::cout<<" BOT("<<bot_x<<","<<bot_y<<")";
    std::cout<<" REWARD("<<reward<<")";
  }

  void advance_timestep()
  {
    current_time ++;
    if(is_food_at(bot_x, bot_y))
      reward = true;
    else
      reward = false;
  }
};
