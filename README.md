# mazeSolver

A maze has walls, open locations, a start location, and an end location.
//    The initial maze is read from a file. See problem spec for file format.
//    The user can get a location from the maze, and keep track of which locations
//    have been visited. Locations are represented by x-y coordinates or Point objects.
//    The origin (0,0) is the lower left corner of the graph; the x-coordinate moves
//    left to right across the x axis; the y-coordinate moves bottom to top up the y axis.
//    The set() method is private, as the maze should not be changed once it has been
//    read from the file.

// Constructor
	// Accepts file name as a parameter
	// Reads the file and initializes start and end location and Maze Matrix and visited matrix
  
  // printMaze
	// Prints current maze to console
  
  // printMazeVisited
	// Prints current maze to console with visited locations marked by a 'V'
  
  // toString
	// convert Maze to a string representation
  
  // toStringVisited
	// convert visited Maze to a string representation with visited locations marked by a 'V'
  
  //getNumRows() 
  //getNumCols()
  	// Get the maze dimensions
    
    
   //char get (int x, int y) const;
	char get (Point location) const;
    // Get an item at the given coodinates from the maze matrix.
	// Throws std::range_error if the coordinates are not within the maze bounds
  
  
  void markVisited (int x, int y);
	void markVisited (Point location);
  // Set visited flag in the visited matrix at the given coodinates.
	// Throws std::range_error if the coordinates are not within the maze bounds
  
  
  bool hasBeenVisited (int x, int y) const;
	bool hasBeenVisited (Point location) const;
  // Get visited flag at the given coodinates from the visited matrix.
	// Throws std::range_error if the coordinates are not within the maze bounds
  
  
  bool isOpen(int x, int y) const;
	bool isOpen(Point location) const;
  // Determine if the given coodinates is an open location
	// Throws std::range_error if the coordinates are not within the maze bounds
  
  
  bool isWall(int x, int y) const;
	bool isWall(Point location) const;
  // Determine if the given coodinates is a wall location
	// Throws std::range_error if the coordinates are not within the maze bounds
