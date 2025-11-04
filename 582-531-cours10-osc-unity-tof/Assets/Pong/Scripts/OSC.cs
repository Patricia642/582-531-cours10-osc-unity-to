using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using extOSC;

public class OSC : MonoBehaviour
{
    public extOSC.OSCReceiver oscReceiver;

    public static float Proportion(float value, float inputMin, float inputMax, float outputMin, float outputMax)
{
    return Mathf.Clamp(((value - inputMin) / (inputMax - inputMin) * (outputMax - outputMin) + outputMin), outputMin, outputMax);
}

void TraiterOsc(OSCMessage message)
{
// Si le message n'a pas d'argument ou l'argument n'est pas un Int on l'ignore
    if (message.Values.Count == 0)
    {
        Debug.Log("No value in OSC message");
        return;
    }
        
    if (message.Values[0].Type != OSCValueType.Int)
    {
        Debug.Log("Value in message is not an Int");
        return;
    }

    int value = message.Values[0].IntValue;

    float position = Proportion(value, 20 , 4095 , -4 , 4 );

    transform.position = new Vector3(transform.position.x, position.z);

  
}

    // Start is called before the first frame update
    void Start()
    {
        oscReceiver.Bind("/MESURE", TraiterOscMESURE);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
