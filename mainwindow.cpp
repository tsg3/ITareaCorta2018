//
// Created by racso on 17/03/18.
//

#include "mainwindow.h"

#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QInputDialog>
#include <QtWidgets/QTextEdit>
#include <QMessageBox>

//Variables globales

int actual = 0;
int posy = 10;
int start;

QString pages[300];
QList<QTextEdit *> texts;
QString texto = "En un lugar de La Mancha, había un señor que leía muchos libros, de "
        "aventuras, caballeros, hidalgos, etc. Un día de tanto leer, se le secó el cerebro, "
        "y perdió el juicio. Se le antojó que quería ser un caballero, y que iba a "
        "enfrentarse a gigantes, a malhechores y todo eso... Emprendió su camina con "
        "unas armaduras viejas que tenia en el desván, y se ‘enamoro’ de una moza, a la "
        "que llamó Dulcinea de Toboso, cogió a su viejo caballo, al que llamó Rocinante, y "
        "se fue en busca de aventuras, poco más adelante, se encontró con un ‘venta’ en "
        "la cual había dos chicas en la puerta. estas al verlo llegar, se asustaron, pero al "
        "ver el lenguaje que empleaban, empezaron a reírse. Entonces un señor que "
        "andaba por ahí recogiendo rastrojos, le vio y le invitó a entrar, después de un "
        "rato, nuestro caballero, se arrodilla delante de él y le suplica, que le haga "
        "caballero, este desconcertado, le sigue la corriente y le dice que sí, y El "
        "Quijote dice que esta noche velará las armas, en la capilla del ‘castillo’, y que "
        "mañana por la mañana se celebrará, la ceremonia de ‘coronamiento’, le dice que "
        "sí pero que va a tener que velar las armas en el patio, que no hay capilla, porque "
        "la han derribado, para construir otra nueva. Llega la noche y el Quijote se "
        "pone a velar sus armas, que están puestas encima de una pila. En esto llega un "
        "señor a coger agua para dársena a los animales, y el Quijote le dice, que no se "
        "atreva a mover sus armas, por que lo pagará con la vida, este pasa de él y "
        "cuando va a mover las armas, para poder coger agua, el Quijote le da con la "
        "lanza en la cabeza y lo dejó inconsciente, en esto llega otro con las misma "
        "intenciones, sin darse cuenta de que estaba el otro en el suelo, cuando hace lo "
        "que el otro, el Quijote sin avisarle le da con la lanza en la cabeza y se la abre "
        "en tres partes o más. Llegan los demás por el ruido del golpe, y le empiezan a "
        "tirar piedras, el ventero, les dice, que se paren quietos, que esta loco y que eso "
        "lo justifica todo. Estos paran, no sé si por que el Quijote arremete contra "
        "ellos, o por las replicas del ventero. El ventero quiere acabar con esta "
        "pesadilla, y celebra la ceremonia en plena noche. El Quijote queda ‘coronado’ "
        "como caballero, y después de un discurso se va. Por el camino (a no se sabe "
        "dónde), oye unos gritos, que salen del monte, el se adentra, y ve a un labrador, "
        "azotando a un niño de más o menos 15 años. Él en voz alta, le dice, que deje al "
        "chiquillo indefenso y que se enfrente a tal poderoso caballero, como don "
        "Quijote de la Mancha, este se achanta, y le dice que no pasa nada, y el Quijote, "
        "le dice que le pague al niño todo lo que le debe, y el le dice que si que le pagará "
        "todo lo que le debe, en casa porque aquí no tiene dinero, entonces, el Quijote "
        "acepta y se va, al ver el labrador, que le ha perdido de vista, dice al niño, que le  "
        "va a pagar lo que le debe pero que va a acrecentar la deuda, y le da tal somanta "
        "de palos, que lo deja, por muerto. "
        "El Quijote, se aleja, y ve acercarse, a unos mercaderes, y le dice que "
        "alaben a su señora, Dulcinea del Toboso, y ellos se ríen del haciéndole burlas. Él "
        "dice que tiene que vengar el honor de su señora, y arremete contra ellos, con "
        "tal fuerza, que su caballo, Rocinante, se queda sin salida, y tropieza en plena "
        "carrera, y se cae, el Quijote se queda tendido en el suelo, y es el motivo de "
        "burla de todos, ellos se empiezan a reír, y él dice que no se huyan, y que cuando "
        "se levante... no le dejan acabar y le dan unos palos impresionantes, se apartan "
        "dejándolo como muerto, poco después pasa por ahí un vecino del Quijote, y le "
        "lleva a casa, por el camino el Quijote le dice unos poemas, y le llama de muchas "
        "formas, dándole nombre de los protagonistas de sus libros. Cuando llegan a su "
        "pueblo, ven que en su casa están los amigos del Quijote, entre los que hay un "
        "cura, y con ellos está la sobrina y el ama del Quijote. Entran y le curan, el ama, "
        "la sobrina y el cura, se van a tirar los libro que le han causado, la perdida del "
        "juicio, y lo queman, cuando el Quijote se despierta, ve que no están los libros, "
        "la sobrina le dice, que se los ha llevado un mago, y el dice que ese mago, es un "
        "cabrón, y que se las va a pagar. Se va a dar una vuelta por el pueblo, cuando "
        "recuerda, que un caballero, debe llevar, consigo, un escudero, entonces va a ver "
        "a un vecino, que es un hombre muy basto, y no sabe leer ni escribir, tienen dos "
        "hijos, y está casado, le convence y se marchan sin avisar, este vecino que se "
        "llama Sancho Panza se lleva a su burro, y algo de comer, en las alforjas, cuando "
        "llevan algo de camino, (no mucho), se encuentran, con unos molinos de viento, "
        "que al Quijote le recuerdan a unos gigantes, y Sancho le dice, que no, que son "
        "molinos de viento, no le hace caso, y los ataca, y como se levanta viento, las "
        "aspan se Mueven y los mandar a unos cuantos metros, se quedan molidos "
        "tirados en el suelo, y dice, que eso le ha pasado que el mago (de los libros) los "
        "ha convertido en molinos, porque pensaba que los iba a derrotar. Se levanta y "
        "se ponen a caminar, cuando de repente, se encuentran con unos frailes, el se "
        "acerca, y dice gritando, que son gente mala, y que suelten a las damas, que van "
        "a la fuerza en el coche de atrás. Los frailes le que no llevan a ningunas damas a "
        "la fuerza, entonces el Quijote, arremete contra ellos y coge su lanza, y quiere "
        "matar a uno de los frailes, pero se deja caer de la mula, Sancho, corre y le "
        "quita las ropas al fraile, en esto llegan dos mozos, y le pregunta, que hace "
        "quitándole la ropa al fraile, y dice que, esta batalla la ha ganado el Quijote, y "
        "que esa ropa, por tanto, le pertenece. Mientras tanto, el Quijote está hablando "
        "con las mujeres que iban en el coche, y un escudero, al ver que ese loco, no le "
        "dejaba pasar se enfrenta a él, y se enfrentan el una lucha, muy dura, al final  "
        "gana el Quijote, pero sale herido, por que le han cortado una oreja (no del "
        "todo), se van de ahí, y tanto Sancho, como él se ponen a hablar, el Quijote dice "
        "no se que de un juramento, y Sancho dice que tienen miendo a que los metan en "
        "la cárcel, por meterse, con unos frailes, y con su escudero, el Quijote, le dice "
        "que no pasa nada que los caballeros, no va a la cárcel por muchos homicidios que "
        "cometan. Comen algo, de lo que Sancho lleva, en las alforjas. Emprenden el "
        "camino hacia alguna población en la que acampar, pero no les da tiempo, y se "
        "encuentran frente a unos cabreros, con los que hablan, y entablan una muy "
        "buena, amistad, al día siguiente llega otro y les dice que ha muerto un pastor "
        "llamado Grisóstomo, por amor a una llamada Marcela. Acabado el entierro, se "
        "despidieron, de los cabreros y emprendieron un nuevo camino, adentrándose en "
        "el monte buscado a la Marcela, más adelante, encontraron un descampado, en el "
        "que se podía ver u riachuelo, no se pudieron aguantar y se echaron una siesta. "
        "Aparecieron unos gallegos, con sus jacas, que pacían en la fresca hierba, a "
        "Rocinante, al ver una yegua, se le apeteció, acercarse a ella, y empezó a olerla. "
        "Los gallegos lo vieron venir y cogieron unas estacas de castaño y aporrearon al "
        "pobre Rocinante, se quedo echado en la hierba, y Sancho y don Quijote, al verlo "
        "ahí tirado, se acercaron a los gallegos, con lo cual también salieron ‘estacados’. "
        "Ni Sancho, ni su amo, podían hablar de la tremenda paliza que habían recibido, "
        "con voz débil y dolorosa, dialogaron, y poco a poco se levantaron, como "
        "Rocinante, y su dueño, estaban malos (ya que Sancho, había recibido menos, y "
        "era más joven y el burro se apartó). Montaron a don Quijote, en el burro, y se "
        "acercaron hacia una venta, que como no, don Quijote decía que era un castillo. "
        "En la venta les recibieron muy bien y las hijas del ventero (una era asturiana), "
        "les curaron las heridas, pasaron la noche en unas camas, que eran como muy "
        "incomodas. Pero como el arriero, había quedado, con la hija del ventero, para "
        "‘pasar la noche’, Don Quijote pensaba que, ella se había quedado, prendada de "
        "su ‘hermosura’. El caso es que ella entró en la habitación, y como no veía nada, "
        "el Quijote la cogió, empezó a decirle, que era muy hermosa pero que él estaba, "
        "comprometido, con Dulcinea del Toboso. El arriero, celoso se acercó, y al ver "
        "que ella, se quería despegar del Quijote, no hizo nada pero, como pensó que el "
        "se quería sobrepasar, le arreó un hostiazo, que le hizo sangré en las narices, "
        "entonces con el golpe, se rompió la cama. Tal golpe armó un estruendo "
        "impresionante, que despertó al ventero, ellos al ver que se acercaba el ventero, "
        "se escondieron, el arriero, en su cama y ella en la de Sancho. Sancho estaba "
        "dormido, cuando entró el ventero, con un candelabro, Sancho, se despertó y al "
        "ver el bulto que había a su lado, se asusto, y comenzó a darle golpes, y el "
        "arriero, también, y para colmo también el ventero. Un viejo que era, retirado  "
        "de la policía, llegó y toco, a un hombre(don Quijote) y pensó que era un "
        "cadáver, entonces fue a por un candelabro diciendo a voces que habían muerto "
        "a un hombre. Cuando llegó el viejo, con el candelabro, le pregunto a don "
        "Quijote, que como estaba, este se enfado por el trato, y le dijo, no sé que de "
        "maleducado. El viejo, con el candelabro le pegó en la cabeza y le hizo dos "
        "chichones. Pasado esto, ya arreglado el percance, don Quijote, se dedico a "
        "hacer un bálsamo para ‘arreglarse’ y se lo tomo, se puso muy malo, y le metieron "
        "en la cama con unas mantas, cuando se despertó, y Sancho vio que estaba tan "
        "bien, decidió tomárselo también. Sancho se lo tomo, y pensaron que había "
        "llegado su ora, porque comenzó a vomitar y ponerse de colores. Cuando mejoró "
        "y ya se iban de la venta, les dijeron que tenían que pagar, los gastos, y don "
        "Quijote, le dijo que en los castillos, no se pagaba, y el ventero dijo que como "
        "eso no era un castillo, que no tenían ese problema. Don Quijote pico a su "
        "caballo, y se alejo pero el burro de Sancho no tenia tanto ‘replis’, y le pillaron, "
        "le mantearon, y luego le dejaron marchar. Pero le habían robado las alforjas. "
        "Por coco más adelante, se encontraron, con una polvareda, que pensaron "
        "que era un ejercito. Don Quijote se metió en el medio pero no era un ejercito, "
        "sino una manada de corderos. Don Quijote mató unos siete, y los pastores, (que "
        "eran unos cuantos) le tiraron piedras, una le rompió muelas y dientes y la otra, "
        "le dio en la cabeza. Se tomo un poco de bálsamo, y le vomito en la cara de "
        "Sancho, el cual hizo lo propio. Cuando iban a comer algo, se dio cuenta que le "
        "habían levantado las alforjas. , Se levantaron y se fueron, mas adelante, vieron "
        "a unos hombres con lazas de fuego, y con camisas blancas. Era una funeraria, "
        "que llevaba a un caballero muerto, don Quijote se puso delante y le s replico, uy "
        "les insulto, entonces atacó a uno de ellos y los demás huyeron despavoridos. El "
        "que estaba en el suelo, le dijo que era un cura, y que como le había pegado, que "
        "ya no era caballero, y don Quijote, le dijo que no le había pegado, sino que le "
        "había dado con la lanza, y que pidiera perdón a sus compañeros. Dejaron comida "
        "y muchas cosas por el suelo, y Sancho, claro, se aprovecho. Comieron, y "
        "siguieron el camino, llegaron un descampado y como era de noche, se quedaron "
        "en él. Había mucha sed, y oyeron, ruido de agua, se acercaron, a donde procedía "
        "el ruido, y oyeron unos ruidos, o golpes que estremecían junto, con el ruido de "
        "las hojas y del agua. Don Quijote iba a atacar, cuando Sancho se puso a llorar. "
        "Pero no conmovió al Quijote, y Sancho le ató las patas a rocinante. El Quijote "
        "pensó que estaba embrujado y lo dejó pasar. Al día siguiente se acercaron y "
        "vieron que era un molino que estaba roto. Se acercó un señor con un burro, y "
        "don Quijote, le agredió, y el señor se largo, dejando a su burro, (don Q, le  "
        "agredió porque pensaba que tenia en la cabeza el yelmo de MANBRINO,) "
        "Sancho cambió, las alforjas que eran mucho mejores las del otro que las suyas. "
        "Siguieron su camino, y se encontraron, con una cadena humana, en la "
        "que iban muchos hombres. Estaban encadenados, entre sí, y con ellos se iban "
        "guardas a caballo y a pie. Uno de los guardas, llevaba una escopeta. Don "
        "Quijote, pregunta, que porqué llevaban a esos hombres, privados de su "
        "libertad; el guarda le respondió, que era gente que había cometido algún delito, "
        "y que iban a servir al Rey, el quijote comenzó a preguntar, a uno por uno, que "
        "les había llevado a esta situación. Después de comprobar lo que quería, pensó "
        "que debía de liberarlos, y les dijo a los guardas que los soltaran. Estos no "
        "accedieron, y le dijeron que estaba loco, y se rieron de él. Entonces, él "
        "arremetió contra el que tenia la escopeta, y lo tiró del caballo. Este estaba en "
        "el suelo, y los demás con la ayuda del arma, y de Sancho, consiguieron "
        "reducirlos. Don Quijote, le pidió, que fueran al Toboso, a humillarse, frente a "
        "su señora, Dulcinea del Toboso. Ellos que le tomaron por loco, empezaron a "
        "tirarle piedras, y se largaron. ";

//Interfaz

Window::Window(QWidget *parent) :
        QWidget(parent) {
    setFixedSize(1200, 1200);
    setWindowTitle("Tarea Corta #1");

    m_button = new QPushButton("RUN", this);
    m_button->setGeometry(1025, 10, 150, 40);
    m_button->setCheckable(true);
    connect(m_button, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));

    m2_button = new QPushButton("Scroll UP", this);
    m2_button->setGeometry(1025, 70, 150, 40);
    m2_button->setCheckable(true);
    connect(m2_button, SIGNAL(clicked()), this, SLOT(slotButton2Clicked()));

    m3_button = new QPushButton("Scroll DOWN", this);
    m3_button->setGeometry(1025,130, 150, 40);
    m3_button->setCheckable(true);
    connect(m3_button, SIGNAL(clicked()), this, SLOT(slotButton3Clicked()));

    m2_button->hide();
    m3_button->hide();
}

//Boton RUN

void Window::slotButtonClicked()
{
    for(int u = 0; u<300; u++){
        pages[u] = texto.mid(start,1000);
        start+=1000;
    }


    for(int i = 0; i<3 ; i++){
        texts << new QTextEdit (this);
        texts.at(i)->setText(pages[i]);
        texts.at(i)->setGeometry(100,5 + posy,900,220);
        posy+=220;
        texts.at(i)->show();
    }

    actual+=1;

    m_button->hide();
    m2_button->show();
    m3_button->show();

    qDebug()<<actual;
}

//Boton Scroll UP

void Window::slotButton2Clicked() {

    if (actual == 0 ) {
        alerta = new QMessageBox();
        alerta->warning(this,"Acción Incorrecta","No se puede realizar esta acción ya que no hay una pagina anterior a esta");
        actual+=1;
    } else {
        texts.at(0)->setText(pages[actual - 1]);
        texts.at(1)->setText(pages[actual]);
        texts.at(2)->setText(pages[actual + 1]);
    }
    actual-=1;
}

//Boton Scroll Down

void Window::slotButton3Clicked() {

    texts.at(0)->setText(pages[actual]);
    texts.at(1)->setText(pages[actual+1]);
    texts.at(2)->setText(pages[actual+2]);
    actual+=1;
}
