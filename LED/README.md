# Led

Em algum momento do seu dia, certamente você teve de ligar algum aparelho eletrônico e para notar que estava funcionando, observou o acender de uma “luz”. Esta “luz” trata-se do “**LED**”. Agora, você já se perguntou como ele funciona? E quais são as suas utilidades? 

Então, iremos juntos entender um pouco mais a respeito desse componente eletrônico que nos rodeia no mundo atual.

<div align="center">
<h3>Figura 1: LED verde </h3>	
<img width="1263" height="545" alt="Image" src="https://github.com/user-attachments/assets/51263185-0ae2-40e7-b2e6-5268894e8a32"/>
<h4>Fonte: Olhar digital </h4>
</div>

# O que é o LED?

Para começarmos a decifrar esse componente, primeiramente precisaremos entender o significado de seu nome. Os “LEDs”, ou **Diodos Emissores de Luz**(Light Emitting Diodes), são dispositivos semicondutores que convertem **energia elétrica** em **luz visível**. 

Devido à sua alta eficiência energética e versatilidade, os LEDs têm ampla aplicação. São utilizados em iluminação residencial, comercial e pública, além de semáforos, painéis e cortinas de LED, reduzindo significativamente o consumo de eletricidade. Na microeletrônica, eles atuam como indicadores de funcionamento e alerta em diversos equipamentos. 

<div align="center">
<h3>Figura 2: Estrutura do LED </h3>	
<img width="1263" height="545" alt="Image" src="https://github.com/user-attachments/assets/bc928e9a-cfc2-4c41-b51f-276969a0c350" />
<h4>Fonte: Wikipédia </h4>
</div>

A estrutura de um LED, ilustrada na Figura 2, é composta por um **ânodo** (terminal positivo) e um **cátodo** (terminal negativo). Entre esses terminais encontra-se uma junção semicondutora, formada pela união de uma camada de material do tipo p (positiva) e outra do tipo n (negativa), responsável pelo funcionamento do dispositivo.

Esse processo de emissão de luz baseia-se no fenômeno da **eletroluminescência**, que ocorre quando uma corrente elétrica atravessa a junção semicondutora. Ao ser aplicada uma tensão elétrica entre o ânodo e o cátodo, elétrons e lacunas deslocam-se em direção à junção. Nesse processo, ocorre a recombinação dessas cargas, liberando energia na forma de luz visível.


<div align="center">
<h3>Figura 3: Funcionamento do LED </h3>	
<img width="1263" height="545" alt="Image" src="https://github.com/user-attachments/assets/74354624-f65c-4574-8d23-3f07f8dee9bf" />
<h4>Fonte: Google </h4>
</div>

Essa luz é formada por pequenas partículas chamadas **fótons**, cuja cor depende diretamente do material utilizado na fabricação do LED. Como cada composto libera uma quantidade específica de energia, o componente é capaz de produzir cores distintas, como vermelho, verde, azul ou branco. 


# Simulação

Agora que compreendemos melhor sobre o LED e seu funcionamento, vamos juntos ver na prática como podemos aplicá-los em um arduino (uma plataforma para criar projetos eletrônicos, com hardware e software fáceis de usar) e criar um contador binário. Mas antes de começar, primeiramente precisamos separar os materiais necessários para a montagem do circuito. 

# Materiais utilizados:

- Arduino UNO;
- 5 Jumpers;
- 3 LEDs;
- 3 Resistores (220 Ω);
- 1 Protoboard.

# Montagem do Circuito

Para essa simulação, estaremos utilizando o **Tinkercad**, uma ferramenta virtual que possibilita a criação de protótipos de arduínos sem a necessidade de possuí-los fisicamente.

<div align="center">
<h3>Figura 4: Contador binário com LED </h3>	
<img width="1263" height="545" alt="Image" src="https://github.com/user-attachments/assets/bec75950-b2e2-43a7-adb7-ea2843173268" />
<h4>Fonte: Autoria própria </h4>
</div>

Agora, com o material separado, faça as conexões entre o Arduino e a protoboard conforme a **Figura 5**. Inicialmente, conecte o pino GND (terra) do Arduino ao barramento negativo da protoboard. Em seguida, conecte três pinos digitais do Arduino aos ânodos dos LEDs (vermelho, verde e amarelo). Os cátodos dos LEDs devem ser conectados a uma perna do resistor e a outra deve ser conectada ao barramento negativo (GND) da protoboard, completando o circuito.

# Código 
Após montado, partimos para a construção do código. E é aqui, onde daremos vida ao nosso contador. Por isso, fique atento aos detalhes!

Primeiro, definimos as variáveis que iremos utilizar e atribuímos a porta digital de saída do arduíno:


```cpp
int led1 = 2;
int led2 = 3;
int led3 = 4;
```
Em seguida, iremos para a função ‘void setup()’, onde ela é executada somente uma vez assim que a placa é ligada ou reiniciada, servindo para preparar o sistema antes do código principal rodar.

```cpp
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}
```
Aqui, utilizamos a função pinMode para configurar os pinos representados por nossas variáveis, definindo seu modo de operação como **OUTPUT**(saída). 

Partindo para a função ‘void loop()’, iremos inserir o código principal que será executado repetidamente em ciclo contínuo. Começando com um laço de repetição: 

```cpp
for (int num = 0; num < 8; num++) {
```
O programa vai fazer uma contagem de um valor que inicia no 0 e repete acrescentando 1 enquanto seu valor for menor que 8. Ou seja, o código dentro do “**for**” vai rodar 8 vezes (0, 1, 2, 3, 4, 5, 6, 7).

Nesse momento, entramos em contato com a linguagem nativa dos computadores por meio da utilização dos bits, a menor unidade de informação que um computador pode armazenar e processar, podendo assumir apenas dois estados: 0 ou 1. 

```cpp
    int b0 = num % 2;       
    int b1 = (num / 2) % 2;  
    int b2 = (num / 4) % 2;
```
Cada uma dessas variáveis representa um bit do número armazenado em um ‘num’. Como cada bit só pode assumir os valores de 0 ou 1, o programa separa o número decimal em sua forma binária, identificando quais posições devem ficar ligadas (1) ou desligadas (0). Nesse contexto: 

- b0 corresponde ao bit menos significativo;
- b1  corresponde ao bit do meio;
- b2 corresponde ao bit mais significativo.

Para obter o bit b0, que já ocupa a posição menos significativa, basta extrair diretamente o resto da divisão do número por 2. No caso de b1, o programa divide o número por 2 para aplicar um deslocamento de uma posição para a direita, alinhando o bit do meio na casa inicial para então isolá-lo com o resto da divisão por 2. O mesmo princípio se aplica a b2, onde a divisão por 4 realiza um deslocamento de duas posições para a direita, trazendo o bit mais significativo para a primeira casa, onde ele é finalmente capturado pelo resto da divisão por 2. 

Assim, chegando a penúltima função, o ‘digitalWrite()’ que envia um sinal elétrico (nível lógico alto ou baixo) para um pino digital. Ela vai ligar ou desligar o LED de acordo com o valor (0 ou 1) armazenado nas variáveis: 

```cpp
    digitalWrite(led1, b0);
    digitalWrite(led2, b1);
    digitalWrite(led3, b2); 
```

Finalizando com a função ‘delay()’ que vai adicionar a espera de 1 segundo antes de mostrar o próximo número.

```cpp
delay(1000);
```

Desta forma, concluímos nossa simulação de um contador binário utilizando os LEDs para representá-los. Essa é apenas uma das várias maneiras de aplicar o LED, que faz parte de algum aparelho eletrônico perto de você!

Linkd do circuito no tinkercad: https://www.tinkercad.com/things/eCV0aHjajZD-contador-binario-com-3-leds?sharecode=0NC4vcAwEU4mD_MbRB6D_NJwfa2_0fMpkx3NTu2iYyw

- <p><a href="https://github.com/JoaoGabriel008"> João Gabriel</a></p>

