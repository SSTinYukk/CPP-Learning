package taillog

import (
	"fmt"
	"os"

	"github.com/hpcloud/tail"
)

var (
	tails *tail.Tail
)

func Init(fileName string) (err error) {
	//定义配置文件
	config := tail.Config{
		ReOpen: true, //重新打开
		Follow: true,
		Location: &tail.SeekInfo{
			Offset: 0,
			Whence: os.SEEK_END,
		},
		MustExist: false,
		Poll:      true,
	}
	tails, err = tail.TailFile(fileName, config)
	if err != nil {
		fmt.Println("tail file failed,err", err)
		return
	}
	return
}
