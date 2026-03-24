# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rtdl_demo_interfaces:msg/WorldState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_WorldState(type):
    """Metaclass of message 'WorldState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rtdl_demo_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rtdl_demo_interfaces.msg.WorldState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__world_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__world_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__world_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__world_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__world_state

            from rtdl_demo_interfaces.msg import ObjectState
            if ObjectState.__class__._TYPE_SUPPORT is None:
                ObjectState.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class WorldState(metaclass=Metaclass_WorldState):
    """Message class 'WorldState'."""

    __slots__ = [
        '_robot_room',
        '_holding_object',
        '_robot_x',
        '_robot_y',
        '_robot_yaw',
        '_objects',
    ]

    _fields_and_field_types = {
        'robot_room': 'string',
        'holding_object': 'string',
        'robot_x': 'double',
        'robot_y': 'double',
        'robot_yaw': 'double',
        'objects': 'sequence<rtdl_demo_interfaces/ObjectState>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['rtdl_demo_interfaces', 'msg'], 'ObjectState')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.robot_room = kwargs.get('robot_room', str())
        self.holding_object = kwargs.get('holding_object', str())
        self.robot_x = kwargs.get('robot_x', float())
        self.robot_y = kwargs.get('robot_y', float())
        self.robot_yaw = kwargs.get('robot_yaw', float())
        self.objects = kwargs.get('objects', [])

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.robot_room != other.robot_room:
            return False
        if self.holding_object != other.holding_object:
            return False
        if self.robot_x != other.robot_x:
            return False
        if self.robot_y != other.robot_y:
            return False
        if self.robot_yaw != other.robot_yaw:
            return False
        if self.objects != other.objects:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def robot_room(self):
        """Message field 'robot_room'."""
        return self._robot_room

    @robot_room.setter
    def robot_room(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'robot_room' field must be of type 'str'"
        self._robot_room = value

    @builtins.property
    def holding_object(self):
        """Message field 'holding_object'."""
        return self._holding_object

    @holding_object.setter
    def holding_object(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'holding_object' field must be of type 'str'"
        self._holding_object = value

    @builtins.property
    def robot_x(self):
        """Message field 'robot_x'."""
        return self._robot_x

    @robot_x.setter
    def robot_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'robot_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'robot_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._robot_x = value

    @builtins.property
    def robot_y(self):
        """Message field 'robot_y'."""
        return self._robot_y

    @robot_y.setter
    def robot_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'robot_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'robot_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._robot_y = value

    @builtins.property
    def robot_yaw(self):
        """Message field 'robot_yaw'."""
        return self._robot_yaw

    @robot_yaw.setter
    def robot_yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'robot_yaw' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'robot_yaw' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._robot_yaw = value

    @builtins.property
    def objects(self):
        """Message field 'objects'."""
        return self._objects

    @objects.setter
    def objects(self, value):
        if __debug__:
            from rtdl_demo_interfaces.msg import ObjectState
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, ObjectState) for v in value) and
                 True), \
                "The 'objects' field must be a set or sequence and each value of type 'ObjectState'"
        self._objects = value
