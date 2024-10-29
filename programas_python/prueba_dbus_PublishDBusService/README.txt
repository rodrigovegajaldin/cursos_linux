este programa es una prueba de publicar un servicio en dbus, una vez ejecutado el script, en una terminal ejecutar el siguiente comando

busctl --user call org.ukbaz /org/ukbaz/fibonacci0001 org.ukbaz.calculator1 Fibonacci q 9 
-tendria que responder:
t 34

o

busctl --user get-property org.ukbaz /org/ukbaz/fibonacci0001 org.ukbaz.calculator1 limit 
-tendria que responder:
t 94
