package com.example.prostheticarmsl
import android.Manifest
import android.app.NotificationChannel
import android.app.NotificationManager
import android.content.Context
import android.content.pm.PackageManager
import android.os.Build
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import androidx.core.app.ActivityCompat
import androidx.core.app.NotificationCompat
import androidx.core.app.NotificationManagerCompat
import androidx.core.content.ContextCompat
import java.io.PrintWriter
import java.net.Socket
import android.widget.Button
import android.widget.EditText


class MainActivity : AppCompatActivity() {

    private val arduinoIpAddress = "192.168.42.124"
    private val arduinoPort = 6
    private val channelId = "NotificationChannel"
    private val notificationId = 123

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val thumbUpButton = findViewById<Button>(R.id.thumbUpButton)
        thumbUpButton.setOnClickListener {
            sendDataToArduino("thumb_up")
        }

        val thumbDownButton = findViewById<Button>(R.id.thumbDownButton)
        thumbDownButton.setOnClickListener {
            sendDataToArduino("thumb_down")
        }

        val indexUpButton = findViewById<Button>(R.id.indexUpButton)
        indexUpButton.setOnClickListener {
            sendDataToArduino("index_up")
        }

        val indexDownButton = findViewById<Button>(R.id.indexDownButton)
        indexDownButton.setOnClickListener {
            sendDataToArduino("index_down")
        }

        val middleUpButton = findViewById<Button>(R.id.middleUpButton)
        middleUpButton.setOnClickListener {
            sendDataToArduino("middle_up")
        }

        val middleDownButton = findViewById<Button>(R.id.middleDownButton)
        middleDownButton.setOnClickListener {
            sendDataToArduino("middle_down")
        }

        val ringUpButton = findViewById<Button>(R.id.ringUpButton)
        ringUpButton.setOnClickListener {
            sendDataToArduino("ring_up")
        }

        val ringDownButton = findViewById<Button>(R.id.ringDownButton)
        ringDownButton.setOnClickListener {
            sendDataToArduino("ring_down")
        }

        val pinkyUpButton = findViewById<Button>(R.id.pinkyUpButton)
        pinkyUpButton.setOnClickListener {
            sendDataToArduino("pinky_up")
        }

        val pinkyDownButton = findViewById<Button>(R.id.pinkyDownButton)
        pinkyDownButton.setOnClickListener {
            sendDataToArduino("pinky_down")
        }

        val allUpButton = findViewById<Button>(R.id.allUpButton)
        allUpButton.setOnClickListener {
            sendDataToArduino("all_up")
        }

        val allDownButton = findViewById<Button>(R.id.allDownButton)
        allDownButton.setOnClickListener {
            sendDataToArduino("all_down")
        }

        val sendButton = findViewById<Button>(R.id.sendButton)
        val editText = findViewById<EditText>(R.id.commandEditText)

        sendButton.setOnClickListener {
            val text = editText.text.toString()
            sendDataToArduino(text)
        }
    }

    private fun sendDataToArduino(data: String) {
        Thread {
            try {
                val socket = Socket(arduinoIpAddress, arduinoPort)
                val writer = PrintWriter(socket.getOutputStream(), true)
                writer.println(data)
                writer.close()
                socket.close()
                showNotification("Data Sent", "Successfully sent data to Arduino")
            } catch (e: Exception) {
                e.printStackTrace()
                showNotification("Error", "Failed to send data to Arduino")
            }
        }.start()
    }

    private fun showNotification(title: String, message: String) {
        createNotificationChannel()

        val notificationBuilder = NotificationCompat.Builder(this, channelId)
            .setSmallIcon(R.drawable.ic_launcher_background)
            .setContentTitle(title)
            .setContentText(message)
            .setPriority(NotificationCompat.PRIORITY_DEFAULT)
            .setAutoCancel(true)
        with(NotificationManagerCompat.from(this)) {
            notify(notificationId, notificationBuilder.build())
        }
    }

    private fun createNotificationChannel() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            val name = "Channel Name"
            val descriptionText = "Channel Description"
            val importance = NotificationManager.IMPORTANCE_DEFAULT
            val channel = NotificationChannel(channelId, name, importance).apply {
                description = descriptionText
            }

            val notificationManager: NotificationManager =
                getSystemService(Context.NOTIFICATION_SERVICE) as NotificationManager
            notificationManager.createNotificationChannel(channel)
        }
    }}

