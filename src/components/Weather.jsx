import React, { useState } from "react";
import axios from "axios";

const Search = () => {
    const [city, setCity] = useState("");
    const [weather, setWeather] = useState(null);
    const [error, setError] = useState(null);

    const fetchWeather = async () => {
        try {
            setError(null);
            const response = await axios.get(
                `https://wttr.in/${city}?format=j1`
            );
            setWeather(response.data);
        } catch (err) {
            setError("Nie znaleziono miasta. Spróbuj ponownie.");
            setWeather(null);
        }
    };

    const handleSubmit = (e) => {
        e.preventDefault();
        fetchWeather();
    };

    return (
        <div>
            <form onSubmit={handleSubmit}>
                <input type="text" value={city} onChange={(e) => setCity(e.target.value)} placeholder="Wpisz nazwę miasta"/>
                <button type="submit">Sprawdź pogodę</button>
            </form>

            {error && <p style={{ color: "red"}}>{error}</p>}

            {weather && (
                <div>
                    <h2>Aktualna pogoda w mieście {city}</h2>
                    <p>Temperatura: {weather.current_condition[0].temp_C}°C</p>
                    <p>Wilgotność: {weather.current_condition[0].humidity}%</p>
                    <p>Warunki: {weather.current_condition[0].weatherDesc[0].value}</p>

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

                        </tbody>
                    </table>
                </div>
            )}
        </div>
    );
};

export default Search;