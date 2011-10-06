

.section  .text
.global   write_data

; Takes the data in R24:25 and sends out where ever, in this case the UART
write_data:
  rcall put_char
  mov   r24 , r25
  rcall put_char
  
ret ; /* write_data( const uint16_t ) */
