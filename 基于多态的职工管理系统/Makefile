src =$(wildcard *.cpp)

obj =$(patsubst %.cpp,%.o,$(src))

ALL: 职工管理系统.out

职工管理系统.out:$(obj)
	g++ $^ -o $@

%.o:%.cpp
	g++ -c $< -o $@

clean:
	-rm -rf $(obj)