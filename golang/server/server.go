package main

import (
	"github.com/gin-gonic/gin"
	"fmt"
	"net/http"
)

func DHTSensorData(c *gin.Context){
	temp := c.Query("temp")
	c.String(http.StatusOK, "[SERVER] Temperature: " + temp + "°C\n")
}

func Index(c *gin.Context){
	c.HTML(http.StatusOK, "index.html", gin.H{
		"title": "ESP32 Server Default",
	})
}

func main(){

	router := gin.Default()
	router.LoadHTMLGlob("web/templates/**/*")
	router.Static("web/assets", "./web/assets")
	fmt.Println("[SUCCESS] Starting server on :8080")
	router.GET("/", Index)
	router.GET("/dht", DHTSensorData)
	router.Run("0.0.0.0:8080")
	
}