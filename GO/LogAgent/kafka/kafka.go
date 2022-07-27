package kafka

import (
	"log"

	"github.com/Shopify/sarama"
)

var (
	client sarama.SyncProducer
)

func Init(addrs []string) (err error) {
	config := sarama.NewConfig()
	config.Producer.RequiredAcks = sarama.WaitForAll
	config.Producer.Partitioner = sarama.NewRandomPartitioner
	config.Producer.Return.Successes = true
	client, err = sarama.NewSyncProducer(addrs, config)
	if err != nil {
		log.Fatal(err)
		return
	}
	return
}

func SendToKafka(topic, data string) {
	msg := &sarama.ProducerMessage{}
	msg.Topic = topic
	msg.Value = sarama.StringEncoder(data)

	pid, offset, err := client.SendMessage(msg)
	log.Println("Send to Kafaka...")
	if err != nil {
		log.Fatal(err)
	}
	log.Printf("pid:%v offset:%v", pid, offset)

}
