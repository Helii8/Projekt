import React from "react";

const CurrentWeather = ({ city, currentCondition }) => {
    return (
        <div className="current-weather">
            <h2>Aktualna pogoda w {city}</h2>
            <p>Temperatura: {currentCondition.temp_C}°C</p>
            <p>Wilgotność: {currentCondition.humidity}%</p>
            <p>Warunki: {currentCondition.weatherDesc[0].value}</p>
        </div>
    );
};

export default CurrentWeather;