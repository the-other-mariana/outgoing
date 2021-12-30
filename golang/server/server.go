package main

import (
	"github.com/gin-gonic/gin"
	"fmt"
)

func DHTSensorData(c *gin.Context){
	temp := c.Query("temp")
	c.String(200, "[SERVER] Temperature: " + temp + "°C\n")
}

func main(){

	router := gin.Default()
	fmt.Println("[SUCCESS] Starting server on :8080")
	router.GET("/dht", DHTSensorData)
	router.Run("localhost:8080")
	
}