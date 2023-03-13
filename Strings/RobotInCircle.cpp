// 1041. Robot Bounded In Circle
// On an infinite plane, a robot initially stands at (0, 0) and faces north. Note that:
// -> The north direction is the positive direction of the y-axis.
// -> The south direction is the negative direction of the y-axis.
// -> The east direction is the positive direction of the x-axis.
// -> The west direction is the negative direction of the x-axis.
// The robot can receive one of three instructions:
// -> "G": go straight 1 unit.
// -> "L": turn 90 degrees to the left (i.e., anti-clockwise direction).
// -> "R": turn 90 degrees to the right (i.e., clockwise direction).
// The robot performs the instructions given in order, and repeats them forever.
// Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.


bool formCircle(string str){
    int n = str.length();
    int x = 0, y = 0;
    char dir  = 'N';
    for(int i=0; i<n; i++){
        switch(str[i]){
            case 'G':
                if(dir == 'N') y++;
                else if(dir == 'S') y--;
                else if(dir == 'E') x++;
                else if(dir == 'W') x--;
                break;
            case 'L':
                if(dir == 'N') dir = 'W';
                else if(dir == 'S') dir = 'E';
                else if(dir == 'E') dir = 'N';
                else if(dir == 'W') dir = 'S';
                break;
            case 'R':
                if(dir == 'N') dir = 'E';
                else if(dir == 'S') dir = 'W';
                else if(dir == 'E') dir = 'S';
                else if(dir == 'W') dir = 'N';
        }
    }
    return (!x && !y) || dir != 'N';
}


// Time Complexity : O(n)
// Space Complexity : O(1)

