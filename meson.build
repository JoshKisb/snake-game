project('snake', 'cpp')

sfmldep = dependency('sfml-graphics')
inc = include_directories('include')

src_files = [ 
	'main.cpp', 
	'src/eventsystem.cpp', 
	'src/game.cpp', 
	'src/snake.cpp', 
]

executable('snake', src_files,
  include_directories: inc,
  dependencies : sfmldep
)