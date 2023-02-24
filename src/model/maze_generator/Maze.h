#ifndef MAZE_GENERATOR
# define MAZE_GENERATOR

# include <vector>
# include <random>

namespace s21
{
    class Maze{
    private:
        std::size_t width;
        std::size_t height;

        std::vector<std::vector< int > > verWalls;
        std::vector<std::vector< int > > horWalls;

        void setupUniqSets( std::vector< int >& );
        void addVertWalls( std::vector< int >&, std::size_t );
        void addHorWalls( std::vector< int >&, std::size_t );
        void addLastLine( std::vector< int >& );
        void mergeSets( std::vector< int >&, std::size_t );
        void checkHorWalls( std::vector< int >&, std::size_t );
        void setupNewLine( std::vector< int >&, std::size_t);

    public:
        Maze( int, int );

        void Generate( void );

        std::vector<std::vector< int > > GetVerWalls( void ) const;
        void SetVerWalls( std::vector<std::vector< int > >& );
        
        std::vector<std::vector< int > > GetHorWalls( void ) const;
        void SetHorWalls( std::vector<std::vector< int > >& );
    };
    
} // namespace s21



#endif