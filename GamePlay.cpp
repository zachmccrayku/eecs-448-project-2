#include "GamePlay.h"

GamePlay::GamePlay()
{
  canBeFired = false;
}

GamePlay::~GamePlay(){}

void GamePlay::fireAt(Board* CurrentBoard)
{

  //    CurrentBoard[i][j].hitShip();
  //

//      }

bool GamePlay::isSunk()
{
  // determine if ship that was just hit has been sunk
}

bool GamePlay::quitGame()
{
  //
  // cout << "Would you like to quit the game? Y/N";
  // cin >> choice;
  // if (choice == 'y' || choice == 'Y')
  // {
  // return(true);
  // }
  // else
  // {
  //   return(false);
  // }
}

void GamePlay::convertString(string temp)
{

    // do
  // {
  //   cout << "Where would you like to fire?";
  //   cin >> fireAtSpot;
  //   if(fireAtSpot.length() == 2)
  //   { 
  //     fireSpotLetter = int(temp.at(0));
  // 
  //     fireSpotNum = int(temp.at(1));
  //    if(fireSpotNum >= 49 || fireSpotNum <=57)
  //    {
  //      fireSpotNum = fireSpotNum-49;
  //       if(fireSpotLetter >= 65 || fireSpotLetter <= 74)
  //       {
  //         fireSpotLetter= fireSpotLetter - 65;
  //         if(currentBoard[fireSpotNum][fireSpotLetter].getChar() == "_")
  //         {
  //          canBeFired==True;
  //         }
  //        }
  //       else if(fireSpotLetter >= 97 || fireSpotLetter <= 106)
  //       {
  //          fireSpotLetter= fireSpotLetter - 97;
  //         if(currentBoard[fireSpotNum][fireSpotLetter].getChar() == "_")
  //         {
  //          canBeFired==True;
  //         }
  //       }
  //    }
  //   else
  //   {
  //     cout << "Error! Try Again!";
  //    }
  //  }
  //    while(canBeFired == false);
}

bool Board::isSunk( int row, int col)
{
      if(m_grid[row][col].isHorizontal == true)
      {
        for(int i = col; i < numCols; i++)
        {
          if(m_grid[row][i].getChar() == '^')
          {
            return (false)
           }
          if(m_grid[row][i].getChar() == '_')
          {
            if(m_grid[row][i-1].getChar() == '^')
            {
              return(false); 
            }
            else if(i-1 != 0)
            {
             isSunk(m_grid, row, i-1);
            }
            else if(m_grid[row][i-1].getChar() == 'X')
            {
              return(true);
            }
          }
          break;
        }
      }
      else
      {
        for(int i = row; i < numRows; i++)
        {
          if(m_grid[i][col].getChar() == '^')
          {
            return (false)
           }
          if(m_grid[i][col].getChar() == '_')
          {
            if(m_grid[i-1][col].getChar() == '^')
            {
              return(false); 
            }
            else if(i-1 != 0)
            {
             isSunk(m_grid, i-1, col);
            }
            else if(m_grid[i-1][col].getChar() == 'X')
            {
              return(true);
            }
          }
          break;
        }
      }       
}
