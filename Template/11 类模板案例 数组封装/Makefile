src =$(wildcard *.cpp)

obj =$(patsubst %.cpp,%.o,$(src))

ALL: A.out

A.out:$(obj)
	g++ $^ -o $@

%.o:%.cpp
	g++ -c $< -o $@

clean:
	-rm -rf $(obj)