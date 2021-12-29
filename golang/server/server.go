package main

import (
	"github.com/gin-gonic/gin"
	"fmt"
)

func main(){

	router := gin.Default()
	fmt.Println("[SUCCESS] Starting server on :8080")
	router.Run(":8080")
	
}