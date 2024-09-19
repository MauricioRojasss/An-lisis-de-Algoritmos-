#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QApplication>
#include <QMainWindow>

QT_CHARTS_USE_NAMESPACE

void plotBenchmarkResults(const std::vector<double>& bestCaseTimes,
                          const std::vector<double>& worstCaseTimes,
                          const std::vector<double>& averageCaseTimes,
                          const std::vector<int>& sizes) {
    // Crear las series para cada caso
    QLineSeries *bestSeries = new QLineSeries();
    QLineSeries *worstSeries = new QLineSeries();
    QLineSeries *averageSeries = new QLineSeries();

    // Añadir los datos de tiempo y tamaño a las series
    for (int i = 0; i < sizes.size(); ++i) {
        bestSeries->append(sizes[i], bestCaseTimes[i]);
        worstSeries->append(sizes[i], worstCaseTimes[i]);
        averageSeries->append(sizes[i], averageCaseTimes[i]);
    }

    bestSeries->setName("Mejor Caso");
    worstSeries->setName("Peor Caso");
    averageSeries->setName("Caso Promedio");

    // Crear el gráfico
    QChart *chart = new QChart();
    chart->legend()->show();
    chart->addSeries(bestSeries);
    chart->addSeries(worstSeries);
    chart->addSeries(averageSeries);

    // Ejes
    QValueAxis *axisX = new QValueAxis;
    axisX->setTitleText("Tamaño de entrada (N)");
    chart->addAxis(axisX, Qt::AlignBottom);
    bestSeries->attachAxis(axisX);
    worstSeries->attachAxis(axisX);
    averageSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText("Tiempo de ejecución (segundos)");
    chart->addAxis(axisY, Qt::AlignLeft);
    bestSeries->attachAxis(axisY);
    worstSeries->attachAxis(axisY);
    averageSeries->attachAxis(axisY);

    // Crear el objeto para visualizar el gráfico
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(800, 600);
    window.show();

    QApplication::exec();
}
