import React from "react";
const ForecastTable = ({ forecast }) => {
    return (
        <div>
            <h2>Prognoza pogody</h2>
            <table className="forecast-table">
                <thead>
                    <tr>
                        <th>Data</th>
                        <th>Ranek</th>
                        <th>Dzień</th>
                        <th>Wieczór</th>
                        <th>Noc</th>
                    </tr>
                </thead>
                <tbody>
                    {forecast.slice(0, 3).map((day, index) => (
                        <tr key={index}>
                            <td>{day.date}</td>
                            <td>
                                Temp: {day.hourly[2].tempC}°C <br />
                                Warunki: {day.hourly[2].weatherDesc[0].value}
                            </td>
                            <td>
                                Temp: {day.hourly[4].tempC}°C <br />
                                Warunki: {day.hourly[4].weatherDesc[0].value}
                            </td>
                            <td>
                                Temp: {day.hourly[6].tempC}°C <br />
                                Warunki: {day.hourly[6].weatherDesc[0].value}
                            </td>
                            <td>
                                Temp: {day.hourly[0].tempC}°C <br />
                                Warunki: {day.hourly[0].weatherDesc[0].value}
                            </td>
                        </tr>
                    ))}
                </tbody>
            </table>
        </div>
    );
};

export default ForecastTable;