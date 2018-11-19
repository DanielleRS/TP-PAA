#include <chrono>

#include "randomnumber.h"
#include "util.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv)
{
  int integerPartX, integerPartY;
  int numberOfPoints;
  double fractionalPartX, fractionalPartY;
  // Used for random number generation
  const unsigned int superiorLimit = 1000;

  if (stoi(argv[1]) == 0)
  {
    // Generation of input file
    RandomNumber randomNumber(superiorLimit);

    numberOfPoints = stoi(argv[2]);

    cout << numberOfPoints << endl;

    for (int j = 0; j < numberOfPoints; j++)
    {
      integerPartX = randomNumber.generate();
      integerPartY = randomNumber.generate();

      fractionalPartX = randomNumber.generate() / 100.0;
      fractionalPartY = randomNumber.generate() / 100.0;

      cout << integerPartX + fractionalPartX << " " << integerPartY + fractionalPartY << endl;
    }
  }
  else
  {
    vector<Point> points;
    Answer answer;

    readPoints(&points);

    high_resolution_clock::time_point initialTime = high_resolution_clock::now();

    if (stoi(argv[1]) == 1)
    {
      // Find closest points using the exhaustive method (brute force)
      answer = exhaustiveMethod(&points, 0, points.size());
    }
    else if (stoi(argv[1]) == 2)
    {
      // Find closest points using the divide and conquer method
      answer = divideAndConquerMethod(&points);
    }
    else
    {
      // Invalid command line parameter
      cout << "Select one of the available values (0, 1 or 2)" << endl;

      return 1;
    }

    // Print execution time
    high_resolution_clock::time_point finalTime = high_resolution_clock::now();
    duration<double> timeSpan = duration_cast<duration<double> >(finalTime - initialTime);

    cout << timeSpan.count() << endl;

    // Print result
    cout << "Os pontos de coordenadas " << answer.getP1().getX() << ", " << answer.getP1().getY()
         << " e " << answer.getP2().getX() << ", " << answer.getP2().getY()
         << " apresentam a menor distancia entre si, que eh igual a " << answer.getDistance() << endl;
  }

  return 0;
}
