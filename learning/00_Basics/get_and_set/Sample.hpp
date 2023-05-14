#ifndef SAMPLE_H
# define SAMPLE_H

class Sample {

public:

	Sample (void );
	~Sample( void );

	int		getFoo( void )	const;
	void	setFoo( int v );

private:

	int		_foo;
};

#endif