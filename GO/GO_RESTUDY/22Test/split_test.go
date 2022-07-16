package split

import (
	"reflect"
	"strings"
	"testing"
)

func TestSplit(t *testing.T) {
	ret := Split("abaccba", "b")
	want := []string{"a", "acc", "a"}
	if !reflect.DeepEqual(ret, want) {
		t.Errorf("want:%v bug got:%v\n", want, ret)
	}

}
func TestSplit2(t *testing.T) {
	ret := Split("a::b::c", "::")
	want := []string{"a", "b", "c"}
	if !reflect.DeepEqual(ret, want) {
		t.Errorf("want:%v bug got:%v\n", want, ret)
	}

}

func Test4Split(t *testing.T) {
	type testCase struct {
		str  string
		sep  string
		want []string
	}
	testGroup := map[string]testCase{
		"case1": {"abaccba", "b", []string{"a", "acc", "a"}},
		"case2": {"a::b::c", "::", []string{"a", "b", "c"}},
	}
	for name, tc := range testGroup {
		t.Run(name, func(t *testing.T) {
			got := Split(tc.str, tc.sep)
			if !reflect.DeepEqual(got, tc.want) {
				t.Fatalf("want:%v but got:%v", got, tc.want)
			}
		})
	}
}
func BenchmarkSplit(b *testing.B) {
	for i := 0; i < b.N; i++ {
		Split("a:b:a", ":")
	}
}
func BenchmarkSplit2(b *testing.B) {
	for i := 0; i < b.N; i++ {
		strings.Split("a:b:c", ":")
	}
}
